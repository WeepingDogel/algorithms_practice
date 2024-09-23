import os
import time

log_file = "execution_duration_log.txt"
c_program = "src/search/output/linear_search"

# Start the timer
start_time = time.time()

# Execute the C program
os.system(c_program)

# Stop the timer
end_time = time.time()

# Calculate the execution duration
execution_duration = end_time - start_time

# Log the execution duration
with open(log_file, 'a') as log:
    log.write(f"Program { c_program } executed on {time.strftime('%Y-%m-%d %H:%M:%S')}, Duration: {execution_duration:.4f} seconds\n")

print(f"Program { c_program } execution took {execution_duration:.4f} seconds.")
