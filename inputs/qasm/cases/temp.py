with open("./cases/bssfull.qasm", "r") as file_input:
    with open("./cases/bss100.qasm", "w") as output: 
        for line in file_input:
            if (not line.startswith("cx")):
                output.write(line)