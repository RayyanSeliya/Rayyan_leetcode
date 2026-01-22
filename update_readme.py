#!/usr/bin/env python3
import os
import re
import sys

def extract_topics_from_readme(readme_path):
    topics = []
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            content = f.read()
            common_topics = [
                'Array', 'String', 'Hash Table', 'Dynamic Programming',
                'Math', 'Sorting', 'Greedy', 'Depth-First Search',
                'Binary Search', 'Breadth-First Search', 'Tree',
                'Binary Tree', 'Matrix', 'Two Pointers', 'Stack',
                'Heap', 'Graph', 'Linked List', 'Recursion', 'Sliding Window'
            ]
            for topic in common_topics:
                if re.search(r'\b' + re.escape(topic) + r'\b', content, re.IGNORECASE):
                    topics.append(topic)
    except Exception as e:
        # Don't crash; absence of README is not fatal.
        print(f"[debug] Error reading README for topics ({readme_path}): {e}", file=sys.stderr)
    return topics

def get_difficulty(readme_path):
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            content = f.read()
            if '<h3>Easy</h3>' in content or '### Easy' in content:
                return 'Easy'
            elif '<h3>Medium</h3>' in content or '### Medium' in content:
                return 'Medium'
            elif '<h3>Hard</h3>' in content or '### Hard' in content:
                return 'Hard'
    except Exception:
        pass
    return 'Unknown'

def parse_from_dir(dirname):
    # dirname: "1534-count-good-triplets"
    match = re.match(r'(\d+)-(.+)', dirname)
    if match:
        problem_number = match.group(1)
        problem_name = ' '.join(match.group(2).split('-')).title()
        return problem_number, problem_name
    # fallback: try if dirname is just digits
    match2 = re.match(r'(\d+)$', dirname)
    if match2:
        return match2.group(1), dirname
    return None, None

def parse_from_filename(filename):
    # filename: "3523-make-array-non-decreasing.cpp" or "3523.cpp"
    base = os.path.splitext(os.path.basename(filename))[0]
    match = re.match(r'(\d+)-(.+)', base)
    if match:
        return match.group(1), ' '.join(match.group(2).split('-')).title()
    match2 = re.match(r'(\d+)$', base)
    if match2:
        return match2.group(1), base
    return None, None

def update_readme():
    problem_list = []
    seen_paths = set()

    # 1) Directory-based detection (existing behavior)
    for entry in os.listdir('.'):
        if not os.path.isdir(entry) or entry.startswith('.'):
            continue
        cpp_file = os.path.join(entry, f"{entry}.cpp")
        readme_file = os.path.join(entry, "README.md")

        if os.path.exists(cpp_file):
            problem_number, problem_name = parse_from_dir(entry)
            if not problem_number:
                # Try parsing from the cpp filename
                problem_number, problem_name = parse_from_filename(cpp_file)
            difficulty = get_difficulty(readme_file)
            topics = extract_topics_from_readme(readme_file)
            rel_path = cpp_file.replace('\\', '/')
            problem_list.append({
                'number': problem_number or '0',
                'name': problem_name or os.path.splitext(os.path.basename(cpp_file))[0],
                'path': rel_path,
                'difficulty': difficulty,
                'topics': topics
            })
            seen_paths.add(os.path.normpath(rel_path))

    # 2) File-based detection (standalone .cpp files at repo root or nested)
    for root, dirs, files in os.walk('.', topdown=True):
        # skip .git and .github folders (and hidden)
        dirs[:] = [d for d in dirs if not d.startswith('.') and d != '.git']
        for f in files:
            if not f.endswith('.cpp'):
                continue
            full = os.path.join(root, f)
            norm_full = os.path.normpath(full)
            # Avoid duplicates if we already added the same file via directory logic
            if norm_full in seen_paths:
                continue

            # Determine problem number/name
            problem_number, problem_name = parse_from_filename(f)

            # If not found in filename, try parent directory name
            if not problem_number:
                parent = os.path.basename(os.path.dirname(full))
                pn, pn_name = parse_from_dir(parent)
                if pn:
                    problem_number, problem_name = pn, pn_name

            # Look for README next to the cpp file (same dir)
            readme_file = os.path.join(os.path.dirname(full), 'README.md')
            difficulty = get_difficulty(readme_file)
            topics = extract_topics_from_readme(readme_file)
            rel_path = os.path.relpath(full, '.').replace('\\', '/')

            problem_list.append({
                'number': problem_number or '0',
                'name': problem_name or os.path.splitext(os.path.basename(full))[0],
                'path': rel_path,
                'difficulty': difficulty,
                'topics': topics
            })
            seen_paths.add(norm_full)

    # Filter out any entries without a number (optional) or duplicates
    unique = {}
    for p in problem_list:
        key = (p.get('number') or p.get('path'), p.get('path'))
        if key not in unique:
            unique[key] = p
    problem_list = list(unique.values())

    # Sort problems by number if possible, fallback to path
    def sort_key(x):
        try:
            return int(x['number'])
        except Exception:
            return x['path']
    problem_list.sort(key=sort_key)

    # Debug: print summary to help GitHub Actions logs
    print(f"[debug] Found {len(problem_list)} problems to include in README")
    if len(problem_list) > 0:
        print("[debug] Sample entries:")
        for p in problem_list[:10]:
            print(f" - {p['number']} | {p['name']} | {p['path']} | {p['difficulty']}")

    # Write README
    with open('README.md', 'w', encoding='utf-8') as readme_file:
        readme_file.write("# LeetCode Solutions\n\n")
        readme_file.write("Collection of my LeetCode solutions in C++\n\n")

        # Add statistics
        difficulties = {'Easy': 0, 'Medium': 0, 'Hard': 0, 'Unknown': 0}
        for problem in problem_list:
            difficulties[problem['difficulty']] = difficulties.get(problem['difficulty'], 0) + 1

        readme_file.write("## Statistics\n\n")
        readme_file.write("| Difficulty | Count |\n")
        readme_file.write("|------------|-------|\n")
        for diff in ['Easy', 'Medium', 'Hard', 'Unknown']:
            count = difficulties.get(diff, 0)
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
            diff_icon = difficulty_color.get(problem['difficulty'], '⚪')
            readme_file.write(
                f"| {problem['number']} | [{problem['name']}]({problem['path']}) | "
                f"{diff_icon} {problem['difficulty']} | {topics_str} |\n"
            )

if __name__ == "__main__":
    update_readme()
