# Reason for creating this project don't spend the amount of time you can waste on coding.
# Just run this script and it creates a file with a random and easy name.


import namer

project_name = namer.generate()

with open(f"{project_name}.py", "w") as f:
    f.write("""print("Hello, World!")""")

# USE BLACK FOR FORMATTING
