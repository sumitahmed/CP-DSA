import java.io.IOException;
import java.util.*;

public class MainD{

    // Global data structures to represent the graph and its state
    static Map<String, Integer> nameToId = new HashMap<>();
    static int nextId = 0;
    static List<Set<Integer>> adj = new ArrayList<>();
    static Map<Integer, Set<Integer>> restrictions = new HashMap<>();

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        // --- INPUT READING PHASE ---

        // 1. Read initial connections and store
        int nLines = Integer.parseInt(sc.nextLine());
        String[] initialConnections = new String[nLines];
        for (int i = 0; i < nLines; i++) {
            initialConnections[i] = sc.nextLine();
        }

        // 2. Read queries and store
        int qLines = Integer.parseInt(sc.nextLine());
        String[] queries = new String[qLines];
        for (int i = 0; i < qLines; i++) {
            queries[i] = sc.nextLine();
        }

        // 3. Read restrictions and store
        int rLines = Integer.parseInt(sc.nextLine());
        String[] restrictionLines = new String[rLines];
        for (int i = 0; i < rLines; i++) {
            restrictionLines[i] = sc.nextLine();
        }
        sc.close();

        // --- PROCESSING PHASE ---

        // 4. Build initial graph from stored connections
        for (String line : initialConnections) {
            String[] parts = line.split(" ");
            int sourceId = getId(parts[0]);
            for (int j = 1; j < parts.length; j++) {
                int neighborId = getId(parts[j]);
                // Bidirectional connection
                adj.get(sourceId).add(neighborId);
                adj.get(neighborId).add(sourceId);
            }
        }

        // 5. Build restrictions map from stored restrictions
        for (String line : restrictionLines) {
            String[] parts = line.split(" ");
            int sourceId = getId(parts[0]);
            
            // --- FIX APPLIED HERE ---
            // Replaced computeIfAbsent with traditional get/check/put for better compatibility
            Set<Integer> restrictedSet = restrictions.get(sourceId);
            if (restrictedSet == null) {
                restrictedSet = new HashSet<>();
                restrictions.put(sourceId, restrictedSet);
            }
            // --- END OF FIX ---
            
            for (int j = 1; j < parts.length; j++) {
                restrictedSet.add(getId(parts[j]));
            }
        }
        
        // 6. Process queries sequentially
        for (String query : queries) {
            if (query.contains(" to ")) {
                String[] parts = query.split(" to ");
                int sourceId = getId(parts[0]);
                int destId = getId(parts[1]);
                if (isPathPossible(sourceId, destId)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            } else if (query.contains(" connects ")) {
                String[] parts = query.split(" connects ");
                int station1Id = getId(parts[0]);
                int station2Id = getId(parts[1]);
                adj.get(station1Id).add(station2Id);
                adj.get(station2Id).add(station1Id);
            } else if (query.contains(" disconnects ")) {
                String[] parts = query.split(" disconnects ");
                int station1Id = getId(parts[0]);
                int station2Id = getId(parts[1]);
                adj.get(station1Id).remove(station2Id);
                adj.get(station2Id).remove(station1Id);
            }
        }
    }

    /**
     * Gets the integer ID for a station name. If the station is new,
     * it assigns a new ID and initializes its entry in the adjacency list.
     */
    private static int getId(String name) {
        if (!nameToId.containsKey(name)) {
            nameToId.put(name, nextId);
            adj.add(new HashSet<>());
            nextId++;
        }
        return nameToId.get(name);
    }

    /**
     * Performs a Breadth-First Search (BFS) to find if a path exists
     * from a start node to an end node, respecting the travel restrictions.
     */
    private static boolean isPathPossible(int startNode, int endNode) {
        if (startNode == endNode) {
            return true;
        }

        Set<Integer> restrictedNodes = restrictions.getOrDefault(startNode, Collections.emptySet());
        Queue<Integer> queue = new ArrayDeque<>();
        Set<Integer> visited = new HashSet<>();

        queue.add(startNode);
        visited.add(startNode);

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();

            for (int neighbor : adj.get(currentNode)) {
                // If we found the destination, a valid path exists.
                if (neighbor == endNode) {
                    return true;
                }
                
                // An intermediate node can be visited only if it's not restricted for this source
                // and has not been visited yet.
                if (!visited.contains(neighbor) && !restrictedNodes.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(neighbor);
                }
            }
        }

        return false; // No path found
    }
}