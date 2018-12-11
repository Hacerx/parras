#include <iostream>
#include <ctime>

using namespace std;

/*
:::    :::           :::        ::::::::       ::::::::::       :::::::::       :::    :::
:+:    :+:         :+: :+:     :+:    :+:      :+:              :+:    :+:      :+:    :+:
+:+    +:+        +:+   +:+    +:+             +:+              +:+    +:+       +:+  +:+
+#++:++#++       +#++:++#++:   +#+             +#++:++#         +#++:++#:         +#++:+
+#+    +#+       +#+     +#+   +#+             +#+              +#+    +#+       +#+  +#+
#+#    #+#       #+#     #+#   #+#    #+#      #+#              #+#    #+#      #+#    #+#
###    ###       ###     ###    ########       ##########       ###    ###      ###    ###
*/

// calculo de la binomial para anticipar el resultado
unsigned C(unsigned n, unsigned k) {
    if (n == k || k == 0) {
        return 1;
    }
    return C(n - 1, k - 1) * n / k;
}

// Suma 1 en binario
int *sumaBinario(int num[], int size){
  int acarreo = 1;
  for(int i=0; i < size; i++){
    num[i] = num[i] + acarreo;
    if(num[i] == 2){
      num[i] = 0;
      acarreo = 1;
    }else{
      acarreo = 0;
    }
  }
  return num;
}

void mostrar(int num[], int size){
  for(int i=size-1; i >= 0; i--){
    cout << num[i];
  }
  cout << endl;
}

int main(){
  // Puedes modificar
  size_t dimension = 25;
  int unos = 3;
  // elige si quieres unos
  bool cantidadConcretaDeUnos = true;
  // elige si quieres mostrar las posibilidades
  bool mostrarPosibilidades = false;
  // a partir de aquí no
  int posibilidades[dimension];
  bool fin = false;
  // inicializar array a 0s
  for(int i = 0; i < dimension; i++){
    posibilidades[i] = 0;
  }
  int count = 0;
  int resultado;
  if(cantidadConcretaDeUnos){
    resultado = C(dimension, unos);
  }
  unsigned t0, t1;
  t0 = clock();
  while(!fin){
    sumaBinario(posibilidades, dimension);
    if(cantidadConcretaDeUnos){
      if(resultado == count){
        break;
      }
      int aux = 0;
      // si quisieras comprobar un número limitado de unos
      for(int i=0; i < dimension; i++){
        if(posibilidades[i] == 1){
          aux++;
        }
      }
      if(aux == unos){
        count++;
        if(mostrarPosibilidades){
          mostrar(posibilidades, dimension);
        }
      }
      aux = 0;
    }else{
      count++;
      if(mostrarPosibilidades){
        mostrar(posibilidades, dimension);
      }
    }
    fin = true;
    // condicion de parada, si todos son 1s para
    for(int i=0; i < dimension || fin; i++){
      if(posibilidades[i] == 0){
        fin = false;
      }
    }

  }
  t1 = clock();
  double time = (double(t1-t0)/1000);
  cout << "Execution Time: " << time << endl;
  //cout << C(dimension, unos) << endl;
  cout << "Casos a evaluar "<< count << endl;
}
