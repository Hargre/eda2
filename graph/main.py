from graph import Graph

def populate_graph():
    graph = Graph()

    graph.add_node('eu')
    graph.add_node('amigo')
    graph.add_node('pai do amigo')
    graph.add_node('gerente de empresa')
    graph.add_node('governador')
    graph.add_node('presidente')
    graph.add_node('presidente dos eua')

    graph.add_edge('eu', 'amigo')
    #graph.add_edge('amigo', 'pai do amigo')
    graph.add_edge('pai do amigo', 'gerente de empresa')
    graph.add_edge('gerente de empresa', 'governador')
    graph.add_edge('governador', 'presidente')
    graph.add_edge('presidente', 'presidente dos eua')

    return graph

def main_loop():
    graph = populate_graph()

    while True:
        print("Insira a opção desejada:")
        print("0 - Sair")
        print("1 - Listar pessoas conectadas")
        print("2 - Achar a distância entre duas pessoas")

        option = int(input())

        if option == 0:
            break
        elif option == 1:
            graph.print_nodes()
        elif option == 2:
            start = input("Pessoa inicial: ")
            target = input("Pessoa alvo: ")
            distance = graph.distance(start, target)

            print("A distância entre %s e %s é de: %s" % (start, target, distance))

if __name__ == "__main__":
    main_loop()
