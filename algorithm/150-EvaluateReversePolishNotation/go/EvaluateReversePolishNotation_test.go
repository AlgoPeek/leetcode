package solution

import (
    "testing"
)

func TestEvalRPNCase1(t *testing.T) {
    tokens := []string{"2", "1", "+", "3", "*"}
    result := evalRPN(tokens)
    expected := 9
    if result != expected {
        t.Errorf("TestEvalRPNCase1 failed, got %d, expected %d", result, expected)
    }
}

func TestEvalRPNCase2(t *testing.T) {
    tokens := []string{"4", "13", "5", "/", "+"}
    result := evalRPN(tokens)
    expected := 6
    if result != expected {
        t.Errorf("TestEvalRPNCase2 failed, got %d, expected %d", result, expected)
    }
}

func TestEvalRPNCase3(t* testing.T) {
    tokens := []string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}
    result := evalRPN(tokens)
    expected := 22
    if result != expected {
        t.Errorf("TestEvalRPNCase3 failed, got %d, expected %d", result, expected)
    }
}

