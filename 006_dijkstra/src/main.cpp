#include "raylib.h"
#include "raymath.h"
#include "graph.hpp"
#include "graph_node.hpp"
#include "dijkstra.hpp"
#include <cstdio>

int main(void) {
	GraphNode *A = new GraphNode{Vector2{12, 2}};
	GraphNode *B = new GraphNode{Vector2{5, 5}};
	GraphNode *C = new GraphNode{Vector2{20, 5}};
	GraphNode *D = new GraphNode{Vector2{3, 10}};
	GraphNode *E = new GraphNode{Vector2{10, 10}};
	GraphNode *F = new GraphNode{Vector2{16, 10}};
	GraphNode *G = new GraphNode{Vector2{5, 15}};
	GraphNode *H = new GraphNode{Vector2{13, 15}};
	GraphNode *I = new GraphNode{Vector2{20, 13}};
	GraphNode *J = new GraphNode{Vector2{9, 20}};
	GraphNode *K = new GraphNode{Vector2{20, 20}};

	Graph graph = Graph();
	graph.addNode(A);
	graph.addNode(B);
	graph.addNode(C);
	graph.addNode(D);
	graph.addNode(E);
	graph.addNode(F);
	graph.addNode(G);
	graph.addNode(H);
	graph.addNode(I);
	graph.addNode(J);
	graph.addNode(K);

	graph.addEdge(A, B);
	graph.addEdge(A, C);
	graph.addEdge(B, D);
	graph.addEdge(B, E);
	graph.addEdge(C, I);
	graph.addEdge(C, E);
	graph.addEdge(D, G);
	graph.addEdge(E, F);
	graph.addEdge(E, B);
	graph.addEdge(F, H);
	graph.addEdge(G, H);
	graph.addEdge(G, J);
	graph.addEdge(H, I);
	graph.addEdge(H, K);
	graph.addEdge(I, K);

	std::vector<GraphNode*> solutionPath = computeDijkstra(A, H);

	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "uebung 006 dijkstra");

	SetTargetFPS(60);

	std::vector<GraphNode*> nodes = graph.getGraph();

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			// draw connections
			for (GraphNode *node : nodes) {
				for (GraphEdge edge : node->edges) {
					Vector2 direction = Vector2Scale(
						Vector2Normalize(
							Vector2Subtract(
								node->Position,
								edge.end->Position
							)
						),
						0.5
					);
					DrawTriangle(
						Vector2Add(
							Vector2Scale(
								Vector2{
									node->Position.x + direction.y,
									-node->Position.y + direction.x
								},
								18.0f
							),
							Vector2{20, screenHeight - 20}
						),
						Vector2Add(
							Vector2Scale(
								Vector2{
									node->Position.x - direction.y,
									-node->Position.y - direction.x
								},
								18.0f
							),
							Vector2{20, screenHeight - 20}
						),
						Vector2Add(
							Vector2Scale(
								Vector2{
									edge.end->Position.x,
									-edge.end->Position.y
								},
								18.0f
							),
							Vector2{20, screenHeight - 20}
						),
						RED
					);
				}
			}

			// draw solution path
			for (long unsigned int i = 0; i < solutionPath.size() - 1; i++) {
				GraphNode *currentNode = solutionPath[i];
				GraphNode *nextNode = solutionPath[i+1];
				printf(
					"%f, %f -> %f, %f\n",
					currentNode->Position.x,
					currentNode->Position.y,
					nextNode->Position.x,
					nextNode->Position.y
				);
				Vector2 direction = Vector2Scale(
					Vector2Normalize(
						Vector2Subtract(
							currentNode->Position,
							nextNode->Position
						)
					),
					0.2
				);
				DrawTriangle(
					Vector2Add(
						Vector2Scale(
							Vector2{
								currentNode->Position.x + direction.y,
								-currentNode->Position.y + direction.x
							},
							18.0f
						),
						Vector2{20, screenHeight - 20}
					),
					Vector2Add(
						Vector2Scale(
							Vector2{
								currentNode->Position.x - direction.y,
								-currentNode->Position.y - direction.x
							},
							18.0f
						),
						Vector2{20, screenHeight - 20}
					),
					Vector2Add(
						Vector2Scale(
							Vector2{
								nextNode->Position.x,
								-nextNode->Position.y
							},
							18.0f
						),
						Vector2{20, screenHeight - 20}
					),
					GREEN
				);
			}

			// draw nodes
			for (GraphNode *node : nodes) {
				DrawCircleV(
					Vector2Add(
						Vector2Scale(
							Vector2{node->Position.x, -node->Position.y},
							18.0f
						),
						Vector2{20, screenHeight - 20}
					),
					10.0f,
					BLUE
				);
			}

		EndDrawing();
	}
	CloseWindow();

	return 0;
}