#include <iostream>
#include <algorithm> // Para std::find

void imprimeVetor(const int *vetor, int tamanho);

int main()
{
    int vetor[10]{1, 45, 65, 22, 55, 76, 81, 89, 96, 99};
    int valorProcurado;

    imprimeVetor(vetor, 10);

    std::cout << "Digite o número que deseja encontrar: ";
    std::cin >> valorProcurado;

    auto it = std::find(vetor, vetor + 10, valorProcurado);

    if (it != vetor + 10)
    {
        std::cout << "O valor foi encontrado na posição: " << (it - vetor) << std::endl;
    }
    else
    {
        std::cout << "O valor não foi encontrado no vetor.\n";
    }

    return 0;
}

void imprimeVetor(const int *vetor, int tamanho)
{
    std::cout << "Vetor: ";
    for (auto i = 0; i < tamanho; i++)
    {
        std::cout << vetor[i] << " - ";
    }
    std::cout << std::endl;
}