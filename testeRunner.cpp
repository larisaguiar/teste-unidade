#include "testeShoppingCart.cpp"



class TestRunner {
public:
    int runTests() {
        Catch::Session session;
        int result = session.run();

        // Imprime o resultado dos testes
        std::cout << "\n\nRESULTADO DOS TESTES" << std::endl;

        // Relatório de sucesso ou falha
        if (result == 0) {
            std::cout << "Todos os testes foram executados com sucesso!" << std::endl;
        } else {
            std::cout << "Alguns testes falharam. Código de saída: " << result << std::endl;
        }

        // Retorna o código de erro (0 para sucesso, diferente de 0 para falha)
        return result;
    }
};
