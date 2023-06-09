#include <iostream>
#include <functional>
#include <math.h>
#include <derivadas.hpp>
#include <integraisNC.hpp>
#include <integraisGL.hpp>
#include <integraisGC.hpp>
#include <integraisGH.hpp>
#include <integraisGG.hpp>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
    return  (sqrt(exp(x)));
}

void derivada(){
  double x, delta, ordemErro;
  int option = 0;
  cout << "Qual a ordem da derivada que você deseja de 1 a 4: " << endl;
  cin >> option;

  cout << "Agora digite ordenadamente o X e Delta:" << endl;
  cin >> x >> delta;
  auto f = [](double x) { return (x) * (x) * (x) + 3 * x - cos(x); };
  if (option == 1)
  {
    DerivadaPrimeira dv(f);
    double resultado = dv.metodoCentral(x, delta, 2);
    cout << "Resultado da derivada Primeira método Central erro de ordem 2: " << resultado << endl;
    resultado = dv.metodoCentral(x, delta, 4);
    cout << "Resultado da derivada Primeira método Central erro de ordem 4: " << resultado << endl;

    cout << endl;

    resultado = dv.metodoForward(x, delta, 1);
    cout << "Resultado da derivada Primeira método Forward erro de ordem 1: " << resultado << endl;
    resultado = dv.metodoForward(x, delta, 2);
    cout << "Resultado da derivada Primeira método Forward erro de ordem 2: " << resultado << endl;

    cout << endl;

    resultado = dv.metodoBackward(x, delta, 1);
    cout << "Resultado da derivada Primeira método Backward erro de ordem 1: " << resultado << endl;
    resultado = dv.metodoBackward(x, delta, 2);
    cout << "Resultado da derivada Primeira método Backward erro de ordem 2: " << resultado << endl;
  }
}

void integral(){
  int option, nop;
  cout << "Digite o tipo de derivada que deseja obter e o número de pontos(2 a 4):\n1 - Newton-cotes\n2 - Gauss-Legendre\n3 - Gauss-Chebyshev\n4 - Gauss-Hermite\n5 - Gauss-Laguerre\n";
  cin >> option >> nop;
  if (option == 2){
    auto fs = [](double s) { 
      double x = ((-1+1)/2) + ((1 + 1)/2) * tanh((pi/2) * sinh(s));
      return 1/(pow(x, (2/3))) * ((pi/2) * ((cosh(s))/(pow((cosh(pi/2 * sinh(s))), 2))));};
    auto f = [](double s){
      double x = ((0+2)/2) + ((2 - 0)/2) * tanh((pi/2) * sinh(s));
      return 1/(pow(pow(x, 2), 1/3)) * 1/2 * (pi/2 * cosh(s)/pow((cosh(pi/2 * sinh(s))), 2));
    };
    GaussLegendre gl(f, -10, 10);

    double resultado = gl.resolve(1e-10, nop);

    cout << "O resultado da integral de f(x) = x^2 no intervalo [0, 1] é: " << resultado << endl;
  }
  if(option == 3){
    GaussCheb gl(f);

    double resultado = gl.resolve(1e-6, nop);

    cout << "O resultado da integral de f(x) = x^2 no intervalo [-1, 1] é: " << resultado << endl;
  }
  if(option == 4){
    GaussHerm gl(f);

    double resultado = gl.resolve(1e-6, nop);

    cout << "O resultado da integral de f(x) = x^2 no intervalo [-1, 1] é: " << resultado << endl;
  }
  if(option == 5){
    GaussLaguerre gl(f);

    double resultado = gl.resolve(1e-6, nop);

    cout << "O resultado da integral de f(x) = x^2 no intervalo [-1, 1] é: " << resultado << endl;
  }


}

int main() {
  int option = 0;
  cout << "Prototipo do Programa de Metodos Numericos 2:\n\nAutores:\nMurilo Pinheiro\nNatan Maia" << endl << endl;
  while (option != 1 && option !=2){
    cout << "Para começar diga o que deseja fazer:\n1 - Derivada\n2 - Integral" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
      cout << "Voce escolheu Derivada, agora escolha o que deseja:" << endl;
      derivada();
      break;
    case 2:
      cout << "Voce escolheu Integral, agora escolha o que deseja:" << endl;
      integral();
      break;
    default:
      cout << "Valor inválido." << endl << endl;
      break;
    }
  }
  return 0;
}