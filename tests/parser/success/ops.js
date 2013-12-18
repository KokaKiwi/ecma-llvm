
a = true;
b = a || false;
c = !b;

a = 22 * 10 + 2;
b = (a + 2) * 5;
c = !(a - 2) * (10 << 2);

d = a > 2 ? b : c;
a = b = c = d = true;
