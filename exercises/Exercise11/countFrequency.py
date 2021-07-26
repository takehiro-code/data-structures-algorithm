
import pdb

def countFrequency(word):
    freqLetter = {} # initialize the python dictionary (unordered map)
    # traversing each letter (i.e. key) in word
    for key in word:
        if key not in freqLetter:
            freqLetter[key] = 1 # initialize the count 0 to a corresponding key
        else:
            freqLetter[key] += 1
    
    # printing each key and corresponding count value in the freqLetter
    for key in freqLetter:
        print(key + ": ", freqLetter[key])

if __name__ == "__main__":
    countFrequency("aardvark")