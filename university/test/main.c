#include <stdio.h>
#include <math.h>

#define T 600
#define delta_t 30
/*struct variant_1
 {
   int U_nulevoe, omega_w_nulevoe;
   float k_nulevoe, m, n;
} znacheniya[3];
*/
//--------------------------------------------<< ZADANIE 1 >>-------------------------------------------------//

//----------------< K_1 >----------------------------------//

float k(int t ,float m, float k_nulevoe)
{
    float k_k;
    float stepin_k_1 = powf((float)2.718, (float)m*t);
    float stepin_k_2 = powf((float)2.718, (float)(m*T)/4);
    float stepin_k_3 = powf((float)2.718, (float)(-m)*(t-((3*T)/4)));

    if(t<=T/4 && t>=0)
    {
        k_k = k_nulevoe * stepin_k_1;
    }
    if(t>=T/4 && t<=(3/4)*T)
    {
        k_k = k_nulevoe * stepin_k_2;
    }
    if(t>=((3*T)/4) && t<=T)
    {
        k_k = (k_nulevoe*stepin_k_2)*stepin_k_3;
    }
    return k_k;
}

//------------------< Napruga_U 1 >------------------------//
float napruga_U(int t, int U_nulevoe)
{
    float m, k_nulevoe = 0.001;
    float vajnoe_k = k(t,m,k_nulevoe);
    float resultat_napruga_U = 1;
    float stepin_U_2_1 = powf((float)2.718,(float)(T/2*(-vajnoe_k)));
    float stepin_U_1 = powf((float)2.718,(float)(t*(-vajnoe_k)));
    float stepin_U_2_2 = powf((float)2.718,(float)((-vajnoe_k)*(t-T/2)));
    if(t<=T/2 && t>=0)
    {
        resultat_napruga_U = (U_nulevoe*(1-stepin_U_1));
    }
    else
    {
        resultat_napruga_U = U_nulevoe*(1-stepin_U_2_1)*stepin_U_2_2;
    }
    return (float)resultat_napruga_U;
} 

//------------------<< OMEGA >>--------------------------//

float omega(int omega_nulevoe, float n, int t)
{
    int resultat_omega;
    if(t<=T/4 && t>=0)
    {
        resultat_omega = omega_nulevoe*(1+n*t);
    }
    else
    if(t>=T/4 && t<=(3*T)/4)
    {
        resultat_omega = omega_nulevoe*(1+(n*T/4));
    }
    else
    { 
        resultat_omega = omega_nulevoe*(1+(n*T/4)-n*(t-(3*T/4)));
    }
    return resultat_omega;
}

//-----------------<< MAIN_1 >>-------------------------//

int main(int argc, char **argv)
{
    float stepin_vajna = powf((float)10, (float)(-12));
    float t_g_delta_1 = 0.001;
    float napruga_U_func, vajnoe_k, I_atoe;
    float n = 0.001;
    float m = 0.001;
    float k_nulevoe = 0.001;
    float omega_prosto = 1;
    
    int omega_nulevoe = 6.28*pow((int)10,(int)6);
    int t = 0;
    int U_nulevoe = 200;

    for(t = 0; t <= T;t += 30)
    {
        vajnoe_k = k(t, m, k_nulevoe);
        printf("vajnoe_k = %f\n", vajnoe_k);
        napruga_U_func = napruga_U(t, U_nulevoe);
        printf("napruga_U_func = %f\n", napruga_U_func);
        omega_prosto = omega(omega_nulevoe, n, t);
        printf("omega_prosto = %f\n", omega_prosto);
        I_atoe = napruga_U_func*omega_prosto*stepin_vajna*t_g_delta_1;
        printf("I_atoe = %f\n", I_atoe);
    }
    printf("\n%f\n", omega_prosto);
    printf("\n%f\n", vajnoe_k);

    return 0;
}





/*    FILE *k = fopen("C:\\Users\\shura\\Desktop\\Course WORK\\MY_COURSE_WORK_Ex1\\ishodniki_1.txt", "r");
     fscanf( k, "%d", &a );
    fclose(k);
*/