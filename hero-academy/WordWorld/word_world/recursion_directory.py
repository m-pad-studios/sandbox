#recursive directory search
def print_directory_contents(sPath):
    import os
    for sChild in os.listdir(sPath):
        sChildPath = os.path.join(sPath, sChild)
        if os.path.isdir(sChildPath):
            print_directory_contents(sChildPath)
            print(sChildPath)

        else:
            print(sChildPath)

path = "C:\\Users\mpark\Documents\GitHub"
print_directory_contents(path)