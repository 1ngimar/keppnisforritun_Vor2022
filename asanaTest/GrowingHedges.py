

def count_populated_neighbors(garden, i, j):
    populated_neighbors = 0
    for delta_i in (-1, 0, 1):
        for delta_j in (-1, 0, 1):
            if delta_i == 0 and delta_j == 0:
                # skip over the original square
                continue 
            neighbor_i = i + delta_i
            neighbor_j = j + delta_j
            if 0 <= neighbor_i < len(garden) and 0 <= neighbor_j < len(garden[0]):
                if garden[neighbor_i][neighbor_j] == 1:
                    populated_neighbors += 1
    return populated_neighbors

def simulate_one_year_growth(garden):
    new_garden = [[0 for j in range(len(garden[0]))] for i in range(len(garden))]
    for i in range(len(garden)):
        for j in range(len(garden[0])):
            populated_neighbors = count_populated_neighbors(garden, i, j)

            # if there is a hedge in the square that suffocates
            if garden[i][j] == 1 and populated_neighbors == 8: 
                new_garden[i][j] = 0
            
            # if there is an empty square with a hedge as neighbor
            if garden[i][j] == 0 and populated_neighbors > 0:
                new_garden[i][j] = 1 
            
            # Otherwise we change nothing
            else:
                new_garden[i][j] = garden[i][j]

    return new_garden

def count_adjacent_pairs(garden):
    adj_pairs = 0
    for i in range(len(garden)):
        for j in range(len(garden[0])):
            adj_pairs += count_populated_neighbors(garden, i, j)
    return adj_pairs // 2

def neighbors_after_years(garden, years):
    for year in range(years):
        garden = simulate_one_year_growth(garden)
    for i in range(len(garden)):
        print(garden[i])
    return count_adjacent_pairs(garden)


# garden = [
#     [0, 0, 1],
#     [0, 0, 0]
# ]

garden = [
    [1, 0, 0, 0],
    [1, 1, 0, 0],
    [1, 0, 0, 1]
]
years = 2

print(neighbors_after_years(garden, years))