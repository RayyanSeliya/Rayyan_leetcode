import os
import re

def extract_topics_from_readme(readme_path):
    topics = []
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            content = f.read()
            # Look for common LeetCode topics in the content
            common_topics = [
                'Array', 'String', 'Hash Table', 'Dynamic Programming', 
                'Math', 'Sorting', 'Greedy', 'Depth-First Search', 
                'Binary Search', 'Breadth-First Search', 'Tree', 
                'Binary Tree', 'Matrix', 'Two Pointers', 'Stack',
                'Heap', 'Graph', 'Linked List', 'Recursion', 'Sliding Window'
            ]
            
            for topic in common_topics:
                if re.search(r'\b' + topic + r'\b', content, re.IGNORECASE):
                    topics.append(topic)
    except Exception as e:
        print(f"Error reading README for topics: {e}")
    return topics

def get_difficulty(readme_path):
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            content = f.read()
            if '<h3>Easy</h3>' in content:
                return 'Easy'
            elif '<h3>Medium</h3>' in content:
                return 'Medium'
            elif '<h3>Hard</h3>' in content:
                return 'Hard'
    except Exception:
        pass
    return 'Unknown'

def update_readme():
    problem_list = []
    
    # Walk through all directories
    for dirname in os.listdir('.'):
        # Skip non-directories and special folders
        if not os.path.isdir(dirname) or dirname.startswith('.'):
            continue
            
        # Look for the cpp file and readme
        cpp_file = os.path.join(dirname, f"{dirname}.cpp")
        readme_file = os.path.join(dirname, "README.md")
        
        if os.path.exists(cpp_file):
            try:
                # Extract problem number and name from the directory name
                # Example: "1534-count-good-triplets" -> ("1534", "Count Good Triplets")
                match = re.match(r'(\d+)-(.+)', dirname)
                if match:
                    problem_number = match.group(1)
                    problem_name = ' '.join(match.group(2).split('-')).title()
                    relative_path = cpp_file.replace('\\', '/')
                    
                    # Get difficulty and topics
                    difficulty = get_difficulty(readme_file)
                    topics = extract_topics_from_readme(readme_file)
                    
                    problem_list.append({
                        'number': problem_number,
                        'name': problem_name,
                        'path': relative_path,
                        'difficulty': difficulty,
                        'topics': topics
                    })
            except Exception as e:
                print(f"Error processing {dirname}: {e}")

    # Sort problems by number
    problem_list.sort(key=lambda x: int(x['number']))

    with open('README.md', 'w', encoding='utf-8') as readme_file:
        readme_file.write("# LeetCode Solutions\n\n")
        readme_file.write("Collection of my LeetCode solutions in C++\n\n")
        
        # Add statistics
        difficulties = {'Easy': 0, 'Medium': 0, 'Hard': 0, 'Unknown': 0}
        for problem in problem_list:
            difficulties[problem['difficulty']] += 1
        
        readme_file.write("## Statistics\n\n")
        readme_file.write("| Difficulty | Count |\n")
        readme_file.write("|------------|-------|\n")
        for diff, count in difficulties.items():
            if diff != 'Unknown' or count > 0:
                readme_file.write(f"| {diff} | {count} |\n")
        readme_file.write(f"| **Total** | **{sum(difficulties.values())}** |\n\n")

        # Add problems table
        readme_file.write("## Problems\n\n")
        readme_file.write("| # | Problem | Difficulty | Topics |\n")
        readme_file.write("|---|---------|------------|--------|\n")
        
        for problem in problem_list:
            topics_str = ', '.join(problem['topics']) if problem['topics'] else 'N/A'
            difficulty_color = {
                'Easy': '🟢',
                'Medium': '🟡',
                'Hard': '🔴',
                'Unknown': '⚪'
            }
            diff_icon = difficulty_color[problem['difficulty']]
            
            readme_file.write(
                f"| {problem['number']} | [{problem['name']}]({problem['path']}) | "
                f"{diff_icon} {problem['difficulty']} | {topics_str} |\n"
            )

if __name__ == "__main__":
    update_readme()
