{   uint32_t mask = x;

    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;

    mask = mask >> 1;

    return x & mask;
}