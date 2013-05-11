#!/usr/bin/env node

function swap(elems)
{
    var tmp = elems[0];
    elems[0] = elems[1];
    elems[1] = tmp;
}

function index()
{
    return 2;
}

var tab = [0, 0, 0, 0, 0, 0, 0, 'Hello world!'];
