import namer

project_name = namer.generate()

with open(f"{project_name}.py", "w") as f:
    f.write("""print("Hello, World!")""")
