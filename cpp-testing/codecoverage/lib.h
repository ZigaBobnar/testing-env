#pragma once

int a(int b, int c) {
    if (b > c) {
        return b * c;
    } else {
        if (c > 10) {
            return b;
        }


        if (b + c == 32) {
            return b / c;
        }
    }
}
