
switch (o.varname)
{
    case 1:
        break;

    case 'test':
        break;

    case (function() { return false; })():
        break;

    default:
        break;
}
