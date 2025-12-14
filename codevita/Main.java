import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner; // Import Scanner
import java.util.Set;

/**
 * Final Attempt.
 * Switched to Scanner for more flexible input parsing.
 * The file MUST be named Main.java
 */
public class Main {

    static class Brick {
        char type;
        Brick(char type) { this.type = type; }
    }

    static int N;
    static int[][] brickIdGrid;
    static List<Brick> bricks;
    static List<Set<Integer>> adj;
    static int startBrickId = -1, destBrickId = -1;

    public static void main(String[] args) throws IOException {
        parseAndBuildGraph();
        System.out.println(solve()); // Using the simplest standard output
    }

    private static void parseAndBuildGraph() {
        Scanner sc = new Scanner(System.in); // Use Scanner
        
        N = sc.nextInt();
        brickIdGrid = new int[N][N];
        bricks = new ArrayList<>();
        bricks.add(new Brick(' ')); // Dummy brick at index 0
        int currentBrickId = 0;

        for (int i = 0; i < N; i++) {
            String line = sc.next(); // Read the next token/line of input
            int col = 0;
            int j = 0;
            while (j < line.length() && col < N) {
                int count = 0;
                while (j < line.length() && Character.isDigit(line.charAt(j))) {
                    count = count * 10 + (line.charAt(j) - '0');
                    j++;
                }
                char type = line.charAt(j);
                j++;

                currentBrickId++;
                bricks.add(new Brick(type));
                if (type == 'S') startBrickId = currentBrickId;
                if (type == 'D') destBrickId = currentBrickId;

                for (int k = 0; k < count && col < N; k++) {
                    brickIdGrid[i][col] = currentBrickId;
                    col++;
                }
            }
        }
        sc.close(); // Close the scanner

        // The rest of the logic is identical
        adj = new ArrayList<>(bricks.size());
        for (int i = 0; i < bricks.size(); i++) {
            adj.add(new HashSet<>());
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                int id1 = brickIdGrid[r][c];
                if (c + 1 < N) {
                    int id2 = brickIdGrid[r][c + 1];
                    if (id1 != id2) {
                        adj.get(id1).add(id2);
                        adj.get(id2).add(id1);
                    }
                }
                if (r + 1 < N) {
                    int id2 = brickIdGrid[r + 1][c];
                    if (id1 != id2) {
                        adj.get(id1).add(id2);
                        adj.get(id2).add(id1);
                    }
                }
            }
        }
    }
    
    private static int solve() {
        if (startBrickId == -1 || destBrickId == -1) return -1;

        int[] dist = new int[bricks.size()];
        Arrays.fill(dist, Integer.MAX_VALUE);
        Deque<Integer> dq = new ArrayDeque<>();

        dist[startBrickId] = 0;
        dq.addFirst(startBrickId);

        while (!dq.isEmpty()) {
            int u = dq.removeFirst();

            if (u == destBrickId) {
                return dist[u];
            }

            for (int v : adj.get(u)) {
                if (bricks.get(v).type == 'R') continue;

                int cost = (bricks.get(v).type == 'G') ? 1 : 0;
                if (dist[u] != Integer.MAX_VALUE && dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    if (cost == 1) {
                        dq.addLast(v);
                    } else {
                        dq.addFirst(v);
                    }
                }
            }
        }
        return dist[destBrickId];
    }
}