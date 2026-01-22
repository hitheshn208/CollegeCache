#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float coeff;
    int expon;
}polynomial;

polynomial terms[100];
int avail = 0;

int COMPARE(int a, int b)
{
    if(a>b)
        return -1;
    if(a<b)
        return 1;
    else
        return 0;
}

void attach(float coeff, int expon)
{
    if(avail > 100)
    {
        printf("Too many elements...\n");
        exit(0);
    }

    terms[avail].coeff = coeff;
    terms[avail++].expon = expon;
    return;
}

void polyadd(int sa, int fa, int sb, int fb)
{
    int sum;
    while(sa<=fa && sb<=fb)
    {
        switch(COMPARE(terms[sa].expon, terms[sb].expon))
        {
            case -1 : attach(terms[sa].coeff, terms[sa].expon);
                sa++;
                break;

            case 0 : 
                sum = terms[sa].coeff + terms[sb].coeff;

                if(sum)
                    attach(sum, terms[sa].expon);
                sa++;
                sb++;
                break;

            case 1 : attach(terms[sb].coeff, terms[sb].expon);
                sb++;
                break;
        }
    }

    if(sa <= fa)
        for(int i = sa; i<=fa; i++)
            attach(terms[i].coeff, terms[i].expon);
    if(sb <= fb)
        for(int i =sb; i<=fb; i++)
            attach(terms[i].coeff, terms[i].expon);
}

int main()
{
    int na, nb, sa, fa, sb, fb, sc, ae, be;
    float ac, bc;
    sa = 0;
    printf("Enter the number of terms in 1st polynomial: ");
    scanf("%d", &na);
    printf("Enter the coefficient and exponent\n");
    for(int i=0; i<na; i++)
    {
        scanf("%f %d", &ac, &ae);
        attach(ac, ae);
    }
    fa = avail-1;
    sb = avail;
    printf("Enter the number of terms in 2nd polynomial: ");
    scanf("%d", &nb);
    printf("Enter the coefficient and exponent\n");
    for(int i=sb; i<(na+nb); i++)
    {
        scanf("%f %d", &bc, &be);
        attach(bc, be);
    }
    fb = avail-1;
    sc = avail;
    polyadd(sa,fa,sb,fb);

    for(int i=sa; i<=fa; i++)
        printf("+ %.3f x^(%d) ", terms[i].coeff, terms[i].expon);

    printf("\n");

    for(int i=sb; i<=fb; i++)
        printf("+ %.3f x^(%d) ", terms[i].coeff, terms[i].expon);
    printf("\n--------------------------------------------------------------\n");
    for(int i = sc; i<avail; i++)
        printf("+ %.3f x^(%d) ", terms[i].coeff, terms[i].expon);
}