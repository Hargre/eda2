""" Set of classes describing graph elements
    and utilities.
"""

from collections import deque, defaultdict

class Node:
    """ Represents a node in a graph. """
    def __init__(self, value):
        self.value = value
        self.edges = []

class Graph:
    """ Represents an unweighted, undirected graph."""
    def __init__(self, nodes=[]):
        self.nodes = nodes
        self.node_dict = defaultdict(Node)

    def add_node(self, value):
        """ Adds a node to the graph,
            without any edges.
        """
        new_node = Node(value)
        self.nodes.append(new_node)
        self.node_dict[new_node.value] = new_node

    def add_edge(self, from_node, to_node):
        """ Adds an edge between
            two nodes in the graph.
        """
        from_node = self.node_dict.get(from_node)
        to_node = self.node_dict.get(to_node)

        from_node.edges.append(to_node)
        to_node.edges.append(from_node)

    def print_nodes(self):
        """ Uses BFS to print all nodes in the graph. """
        to_visit = deque()
        to_visit.append(self.nodes[0])
        visited = []

        while to_visit:
            current_node = to_visit.pop()
            visited.append(current_node)
            print(current_node.value)

            for node in current_node.edges:
                if node in visited or node in to_visit:
                    continue
                else:
                    to_visit.append(node)
            if not to_visit:
                for node in self.nodes:
                    if node not in visited:
                        to_visit.append(node)


    def distance(self, source_name, target_name):
        """ Modified version of BFS.
            Gives the distance between two
            chosen nodes in the graph.
        """
        source = self.node_dict.get(source_name)
        target = self.node_dict.get(target_name)

        if not source or not target:
            return "Pessoa não encontrada"

        if source == target:
            return 0

        to_visit = deque()
        to_visit.append(source)
        visited = []
        distance = -1

        while to_visit:
            marked_node = to_visit.pop()
            visited.append(marked_node)
            distance += 1

            for node in marked_node.edges:
                if node in visited or node in to_visit:
                    continue
                elif node == target:
                    return distance + 1
                else:
                    to_visit.append(node)

        return "Não existe caminho que conecta estas pessoas"
