package solution

import (
    "testing"
)

func TestLadderLength(t *testing.T) {
    wordList := []string{"hot","dot","dog","lot","log","cog"}
    result := ladderLength("hit", "cog", wordList)
    expected := 5
    if result != expected {
        t.Errorf("TestLadderLength failed, got %d, expected %d", result, expected)
    }
}
