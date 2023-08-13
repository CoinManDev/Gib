import zipfile as z
import os
from sys import argv
import tempfile

tmpdir = tempfile.gettempdir()+"/gib"

def new(name, path):
    rootlen = len(path) + 1
    with z.ZipFile(f"{name}.gib", "w") as master:
        with open("lastest_commit", "w") as f:
            f.write("1")
        with z.ZipFile(f"1.zip", "w") as zip:
            for base, dirs, files in os.walk(path):
                for file in files:
                    file = file
                    fn = os.path.join(base, file)
                    #print(fn)
                    zip.write(fn, fn.removeprefix(path))
        master.write("1.zip")
        os.remove("1.zip")

def main():
    if argv[1] == "new":
        new(argv[2], argv[3])

if __name__ == "__main__":
    main()
