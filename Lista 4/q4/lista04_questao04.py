#Matheus Joranhezon 15/0018428
#Felipe Hargreaves - 15/0009313

def gen_sequence():
    yahoo = "buy Yahoo"
    ebay = "buy Ebay"
    oracle = "buy Oracle"
    amazon = "buy Amazon"

    sequence = [amazon, yahoo, ebay, yahoo, yahoo, oracle]

    return sequence

def gen_subsequence():
    yahoo = "buy Yahoo"
    ebay = "buy Ebay"
    oracle = "buy Oracle"
    amazon = "buy Amazon"

    subsequence = [amazon, yahoo, ebay, yahoo, oracle]

    return subsequence

def is_subsequence(sequence, subsequence):
    """ Given two sequences, returns whether the second is a subsequence of the first. """
    events_found = 0
    for event in sequence:
        if event == subsequence[events_found]:
            events_found += 1
        if events_found == len(subsequence):
            return True
    return False

def main():
    sequence = gen_sequence()
    subsequence = gen_subsequence()

    if is_subsequence(sequence, subsequence):
        print("S' is a subsquence of S")
    else:
        print("Not subsequence")

if __name__ == "__main__":
    main()
