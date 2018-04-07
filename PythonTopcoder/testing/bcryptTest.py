import bcrypt
password = "lol"
salt = bcrypt.gensalt()
# Hash a password for the first time, with a randomly-generated salt
hashed = bcrypt.hashpw(password, salt)
print hashed
print salt
print bcrypt.hashpw("lol", hashed)

# Check that an unencrypted password matches one that has
# previously been hashed
if bcrypt.hashpw("lol", hashed) == hashed:
        print "It matches"
else:
        print "It does not match"