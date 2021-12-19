import csv
import os
import json
from tabulate import tabulate


# COME USARE QUESTO SCRIPT
# 0) Questo script necessita di una versione di python >= 3.6
#
# 1) Eventualmente installare package che vengono importati (i.e. > python3.6 -m pip install tabulate)
#
# 2) Configurare rootdir come path per directory contenente i vari log delle co-simulazioni effettuate
# i.e. "/mnt/c/Users/gxhan/Documents/FormalMethodsProject/Multi-models/VanillaCase/co-sim"
#
# 3) Runnare lo script

rootdir = "/home/student/into-cps-projects/leader_and_follower/FormalMethodsProject/Multi-models/VanillaCase/co-sim"

log_directories = []
for file in os.listdir(rootdir):
    d = os.path.join(rootdir, file)
    if os.path.isdir(d):
        log_directories.append(d)


data_to_output = []

for log_directory in log_directories:
    # Metadata to save from mm.json
    following_x0 = 0
    
    # Data to calculate from outputs.csv
    sum_distance = 0
    max_distance = 0
    max_follow_accel = 0
    min_follow_accel = 5000
    min_distance = 5000
    
    try:
        with open(log_directory + "/mm.json") as json_file:
            data = json.load(json_file)
            following_x0 = data["parameters"]["{FollowingCar}.FollowingCarInstance.x0"]
            
        with open(log_directory + "/outputs.csv", mode='r') as csv_file:
            csv_reader = csv.DictReader(csv_file)
            line_count = 0
            
            
            for row in csv_reader:
                if line_count == 0:
                    # print(f'Column names are {", ".join(row)}')
                    line_count += 1
                else:
                    lead_x = float(row["{LeadingCar}.LeadingCarInstance.x"])
                    follow_x = float(row["{FollowingCar}.FollowingCarInstance.x"])
                    curr_follow_accel = float(row["{FollowingAlgorithm}.FollowingAlgorithmInstance.accel"])
                    curr_distance = lead_x - follow_x
                    sum_distance += curr_distance
                    
                    if curr_distance > max_distance:
                        max_distance = curr_distance
                    
                    if curr_distance < min_distance:
                        min_distance = curr_distance
                        
                    if curr_follow_accel > max_follow_accel:
                        max_follow_accel = curr_follow_accel
                    if curr_follow_accel < min_follow_accel:
                        min_follow_accel = curr_follow_accel
                    
                line_count += 1
                
            
            mean_distance = sum_distance/(line_count-1)
            print(f"Processed {line_count} lines")
            print(f"Max_follow_accel: {max_follow_accel}, Min_follow_Accel: {min_follow_accel}")
            print(f"Min_distance: {min_distance}, Max_distance: {max_distance}, Mean_distance: {mean_distance}")
            data_to_output.append([following_x0, mean_distance, max_distance, min_distance, max_follow_accel, min_follow_accel])
            
    except FileNotFoundError:
        continue
            
print(tabulate(data_to_output, headers=["Following_x0", "Mean Distance", "Max_Distance", "Min_Distance", "Max_following_car_accel", "Min_following_car_accel"]))
