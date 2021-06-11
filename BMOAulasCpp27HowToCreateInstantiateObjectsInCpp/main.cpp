//
//  main.cpp
//  BMOAulasCpp27HowToCreateInstantiateObjectsInCpp
//
//  Created by Breno Medeiros on 10/06/21.
//

#include <iostream>
#include <string>


//Existem duas principais areas da memoria, em que na hora de instanciarmo/criaros uma classe precisaremos decidir
// onde será alocado, e elas sao 'stack'(Pilha) e 'heap'(Tb Pilha, mas no sentido de amontoado). Ha diferencas funcionais:
//Stack: Tem TempoDeVide(LifeTime) automatico, que é definido até que se chegue no fim do escopo em que foi criado.
// Alocar no 'Stack' é mais rapido(performatico) do que alocar no 'Heap'.
// No entanto, uma desvantagem do 'Stack' é que ele é limitado(dependendo do Sistema Operacional coisa de 2MB por ex)
//Heap:  Tem um tempo de vida manual, que apesar de dar mais liberdade ao desenvolvedor, vem com o risco de esquecerem de
// desalocar a memoria, tornando o programa cada vez mais pesado devido ao esgotamento de memoria do aparelho que o executar
// Alocar no 'Heap' é mais demorado(lento) do que alocar no 'Stack'.
// No entanto, uma vantagem do 'Heap' é que ele possui uma memoria bem maior que o Stack.

using Texto = std::string;

class Entidade {
private:
    Texto m_Nome;
public:
    Entidade():
            m_Nome("Desconhecido") {
        
    }
    Entidade(const Texto& nome):
            m_Nome(nome) {
        
    }
    const Texto& GetNome() const {
        return m_Nome;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    //Instanciando(Criando) em uma 'Stack':
    Entidade entidadeStack("Breno"); //Tambem funciona escrever "Entidade entidade = Entidade("Breno");"
    std::cout << entidadeStack.GetNome() << std::endl;
    
    // Um truque para passar uma instancia 'Stack' para o escopo acima:
    Entidade* entidadeStackComTruque;
    {
        Entidade entidadeTempStack("BrenoTempStack");
        entidadeStackComTruque = &entidadeTempStack;
        std::cout << entidadeTempStack.GetNome() << std::endl;
    }
    
    
    
    //Instanciando(Criando) em uma 'Heap':
    Entidade* entidadeHeap;
    { //Repare que na linha abaixo, ao usarmos o 'new' estamos iniciando em outro canto, e retornando/aramazenando o ponteiro
        Entidade* entidadeTempHeap = new Entidade("BrenoTempHeap");
        entidadeHeap = entidadeTempHeap;
        std::cout << entidadeTempHeap->GetNome() << std::endl;
    }
    //Repare que podemos usar o 'delete' na linha abaixo da entidadeTempHeap(que fora do escopo acima chamamos de entidadeHeap).
    delete entidadeHeap; //Qnd fazemos isso ficamos responsaveis por 'delete' essa memoria, por o Cpp n o fará por nos
    // Então lembre-se, sempre que usar a PalavraChave(KeyWord) 'new', voce ficara responsavel por colocar o 'delete'.
    
    
    
    //Conclusao: A nao ser que voce precise criarUmaInstanciaExtremamenteGrande ou controlarAMemoria, sempre opite pela 'Stack',
    // alem de que alocar na 'Stack' é mais rapido.
    
    
    return 0;
}
