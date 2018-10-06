package solution

import (
    "testing"
)

func TestConvertToBase7(t *testing.T) {
    result := convertToBase7(100)
    if result != "202" {
        t.Errorf("convertToBase7 failed, got '%s', expected '202'", result)
    }
}
