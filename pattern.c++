

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>

struct CubeState {
    // Representation of cube state
    

    //array of colors
    enum color = {
            WHITE, YELLOW, RED, ORANGE, BLUE, GREEN, NONE
    }

    struct CubeState {
    // 6 faces, 
    //  cube is solved by default
    std::array<Color, 54> stickers;

    CubeState() {
        
        for (int face = 0; face < 6; face++) {
            for (int i = 0; i < 9; i++) {
                stickers[face * 9 + i] = static_cast<Color>(face); 
            }
        }
    }
    
    bool isGoal() const {
        // Return true if this state is solved
    }
    
    std::vector<CubeState> getNeighbors() const {
        //All valid next moves
    }
    
    int heuristic() const {
        //   distance to goal
    }

    bool operator==(const CubeState &other) const {
        // Comparison of two cube states for equality
    }
};


struct CubeHasher {
    size_t operator()(const CubeState &state) const {
        // cube data representation
    }
};

struct Node {
    CubeState state;
    int g;  // cost from start to this node
    int f;  
    std::vector<std::string> path; // moves taken to reach here
};

struct CompareNode {
    bool operator()(const Node &a, const Node &b) {
        return a.f > b.f; 
    }
};

std::vector<std::string> AStarSolve(const CubeState &start) {
    std::priority_queue<Node, std::vector<Node>, CompareNode> openSet;
    std::unordered_set<CubeState, CubeHasher> closedSet;

    openSet.push({start, 0, start.heuristic(), {}});

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.state.isGoal()) {
            return current.path; // solution found
        }

        if (closedSet.find(current.state) != closedSet.end()) {
            continue;
        }
        closedSet.insert(current.state);

        for (CubeState neighbor : current.state.getNeighbors()) {
            if (closedSet.find(neighbor) == closedSet.end()) {
                int tentative_g = current.g + 1; // assumptioon
                int f = tentative_g + neighbor.heuristic();
                std::vector<std::string> newPath = current.path;

                 // newPath 
                openSet.push({neighbor, tentative_g, f, newPath});
            }
        }
    }

    return {}; // no solution reached
}

int main() {
    CubeState scrambled;
    //   scrambled cube state  
    
    std::vector<std::string> solution = AStarSolve(scrambled);

    if (!solution.empty()) {
        std::cout << "Solution moves:\n";
        for (const auto &move : solution) {
            std::cout << move << " "
        }
    } else {
        std::cout << "No solution found.";
    }
    return 0;
}
