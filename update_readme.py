import os

def update_readme():
    problem_list = []
    for filename in os.listdir('.'):
        if filename.endswith('.py') and filename != "update_readme.py":
            try:
              with open(filename, 'r') as file:
                first_line = file.readline().strip()
                problem_name = first_line[2:] if first_line.startswith('//') else filename
                problem_list.append((problem_name, filename))
            except Exception as e:
              print(f"Could not read first line for {filename}: {e}")

    with open('README.md', 'w') as readme_file:
        readme_file.write("# LeetCode Solutions\n\n")
        readme_file.write("Here's a list of LeetCode problems I've solved:\n\n")
        for problem_name, filename in problem_list:
            readme_file.write(f"- [{problem_name}]({filename})\n")

if __name__ == "__main__":
    update_readme()
