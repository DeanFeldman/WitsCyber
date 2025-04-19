
message =  input()
shift = int(input())

def CC(message, shift):
    result = ""
    for char in message:
        if 'A' <= char <= 'Z':
            base = ord('A')     
            result += chr((ord(char)-base + shift)%26+base)
        elif 'a' <= char <= 'z':
            base = ord('a')
            result += chr((ord(char)-base + shift)%26+base)
        else:
            result += char
    return result
encypted = CC(message,shift)
print(encypted)