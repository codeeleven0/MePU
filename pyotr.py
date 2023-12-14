import sys
split = "+"
begin = "#"
end = "!"
compiled = ""
with open(sys.argv[1]) as file:
    x = file.read()
    y = x.split("\n")
    for line in y:
        instr = line.split(" ")[0]
        # there are 7 types so no problem
        if instr == "mov":
            args = line.removeprefix("mov ").split(", ")
            compiled += begin+"0"+split+args[0]+split+args[1]+end
        elif instr == "mvar":
            args = line.removeprefix("mvar ").split(", ")
            compiled += begin+"1"+split+args[0]+split+args[1]+end
        elif instr == "mreg":
            args = line.removeprefix("mreg ").split(", ")
            compiled += begin+"2"+split+args[0]+split+args[1]+end
        elif instr == "exec":
            compiled += begin+"3"+end
        elif instr == "clr":
            compiled += begin+"4"+end
        elif instr == "hlt":
            compiled += begin+"5"+end
        elif instr.endswith(":"):
            compiled += begin+"6"+split+instr.split(":")[0]+split+instr.split(":")[1].replace('"',"")
with open(sys.argv[2] if len(sys.argv) > 2 else "a.out","w") as output:
    output.write(compiled) 