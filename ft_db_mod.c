double     ft_db_mod(double a, double b)
{
    double  mod;
    int     dv;

    dv = (int)(a / b);
    mod = a - ((double)dv * b);
    return (mod);
}