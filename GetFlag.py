import random

def decrypt_flag(x, y, z):
    try:
        if x**3 + y**3 + z**3 != 42:
            return "Incorrect values! Try again."

        with open("C:\\Users\\deanf\\Downloads\\flag.enc", "r") as f:
            hex_enc = f.read().strip()

        random.seed(x**3 + y**3 + z**3)
        key = [random.randint(0, 255) for _ in range(len(hex_enc) // 2)]

        encrypted_bytes = [int(hex_enc[i:i+2], 16) for i in range(0, len(hex_enc), 2)]
        decrypted_flag = "".join(chr(encrypted_bytes[i] ^ key[i]) for i in range(len(encrypted_bytes)))
        return decrypted_flag
    except Exception as e:
        return f"Error: {e}"
x = int(input("Enter first number (x): "))
y = int(input("Enter second number (y): "))
z = int(input("Enter third number (z): "))

flag = decrypt_flag(x, y, z)
print("Decrypted Message:", flag)
