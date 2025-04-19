import crypt

TARGET = "$6$KbKjQhF1$HdcCNKVZ5qPbmIlkVtdSuXlf7qLyHKM4L1lAZNkGSbPAzBRsBhZm5xNIQhXEkMNpnmOB2ABrLl2wftpU5yacx1"
SALT   = "$6$KbKjQhF1$"

with open("/mnt/c/Users/deanf/Downloads/dawgs (1).txt") as f:
    for word in f:
        pwd = word.strip()
        if crypt.crypt(pwd, SALT) == TARGET:
            print("🏆 Cracked! The secret is:", pwd)
            break
