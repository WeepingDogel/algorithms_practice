import os
import time

log_file = "execution_duration_log.txt"

# List of C programs to compile and test
c_programs = [
    {
        "name": "test_sorting_algorithms",
        "source_files": [
            "src/sort/test_sorting_algorithms.c",
            "src/sort/quick_sort.c",
            "src/sort/insertion_sort.c",
            "src/sort/merge_sort.c",
            "src/sort/bubble_sort.c",
            "src/sort/selection_sort.c",
            "src/sort/sort_utils.c"
        ]
    },
    {
        "name": "test_search_algorithms",
        "source_files": [
            "src/search/test_search_algorithms.c",
            "src/search/linear_search.c",
            "src/search/binary_search.c",
            "src/search/jump_search.c",
            "src/search/depth_first_search.c",
            "src/search/breadth_first_search.c",
            "src/search/graph_utils.c"
        ],
        "link_flags": "-lm"  # Add the math library link flag
    }
]

def compile_program(program):
    # Compile the C program
    compile_command = f"gcc -o {program['name']} " + " ".join(program['source_files'])
    if "link_flags" in program:
        compile_command += f" {program['link_flags']}"
    print(f"Compiling {program['name']}...")
    os.system(compile_command)

def run_program(program):
    # Start the timer
    start_time = time.time()

    # Execute the C program
    os.system(f"./{program['name']}")

    # Stop the timer
    end_time = time.time()

    # Calculate the execution duration
    execution_duration = end_time - start_time

    # Log the execution duration
    with open(log_file, 'a') as log:
        log.write(f"Program {program['name']} executed on {time.strftime('%Y-%m-%d %H:%M:%S')}, Duration: {execution_duration:.4f} seconds\n")

    print(f"Program {program['name']} execution took {execution_duration:.4f} seconds.")

def main():
    for program in c_programs:
        compile_program(program)
        run_program(program)

if __name__ == "__main__":
    main()
