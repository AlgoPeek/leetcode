package solution

func ladderLength(beginWord string, endWord string, wordList []string) int {
    dict := map[string]int{}
    for _, word := range wordList {
        dict[word] = 1
    }
    dict[beginWord] = 1

    neighbors := findNeighbors(beginWord, dict)
    dist := 2
    for len(neighbors) > 0 {
        curr := neighbors
        neighbors = []string{}
        for _, neighbor := range curr {
            if (neighbor == endWord) {
                return dist
            }
            neighbors = append(neighbors, findNeighbors(neighbor, dict)...)
        }
        dist += 1
    }
    return 0
}

func findNeighbors(word string, dict map[string]int) []string{
    neighbors := []string{}
    delete(dict, word)
    for i, _ := range word {
        for j := 0; j < 26; j++ {
            array := []rune(word)
            array[i] = rune('a') + rune(j)
            nextword := string(array)
            if _, exist := dict[nextword]; exist {
                neighbors = append(neighbors, nextword)
                delete(dict, nextword)
            }
        }
    }
    return neighbors
}
