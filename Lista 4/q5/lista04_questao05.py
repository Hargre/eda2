def tower_placement(houses, tower_range):
    """
    Given a list of houses in a road, sorted by its distance from one end
    and the range for a cell tower, determine the minimum amount of cell
    towers to be placed such that all houses have service.
    """

    if not houses:
        return

    towers = []
    towers.append(houses[0] + tower_range)

    for house in houses:
        # towers[-1] gets last tower currently listed
        if abs(house - towers[-1]) > tower_range:
            towers.append(house + tower_range)

    return towers

def print_towers(towers):
    """ Prints amount of towers and the position of each one. """
    print(len(towers), 'tower(s):\n')

    for tower in towers:
        print(tower, '\n')


def main():
    houses = [1, 4, 8, 12, 20]
    tower_range = 4

    towers = tower_placement(houses, tower_range)
    print_towers(towers)

if __name__ == "__main__":
    main()
