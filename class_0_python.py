#this is my comment

def main():
    my_string = "Hello 102 class!"
    reversed_string = ""
    for char in my_string:
        reversed_string = char + reversed_string
    print(reversed_string)
    
if __name__ == "__main__":
    main()