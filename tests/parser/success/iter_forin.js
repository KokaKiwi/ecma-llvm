
for (i in [1, 2, 3]);
for (o.counter in [10, 10, 10]);
for (o.get_counter() in [1, 2, 3]); // Not valid at compile-time, but valid at parse-time, for now.

for (var i in [1, 2, 3]);
for (var i = 0 in [4, 5, 6]);
