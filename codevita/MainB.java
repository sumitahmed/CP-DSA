import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

/**
 * Solves the TwoScouts problem by finding two vertex-disjoint paths
 * that minimize the total number of roads traveled.
 *
 * The solution uses DFS to find all paths for the first scout (Arin)
 * and for each of Arin's paths, uses BFS to find the shortest
 * corresponding path for the second scout (Bran).
 */
public class MainB{

    static int N, M;
    static List<List<Integer>> adj;
    static int scoutA, scoutB, outpost;
    static long minPathSum = Long.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        // Initialize adjacency list for the graph (1-indexed)
        adj = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        // Build the undirected graph
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        scoutA = sc.nextInt();
        scoutB = sc.nextInt();
        outpost = sc.nextInt();

        // Constraint: Scouts start in different towns.
        if (scoutA == scoutB) {
            System.out.println("Impossible");
            sc.close();
            return;
        }

        // Start the search for Arin's paths
        Set<Integer> pathForA = new HashSet<>();
        findPathsForScoutA(scoutA, 1, pathForA);

        if (minPathSum == Long.MAX_VALUE) {
            System.out.println("Impossible");
        } else {
            // The result is the minimum sum of path lengths minus 2 (for roads)
            System.out.println(minPathSum - 2);
        }
        sc.close();
    }

    /**
     * Uses DFS to find all simple paths for Scout A from a current town 'u' to the outpost.
     * @param u The current town for Scout A.
     * @param currentLength The number of towns in the path so far.
     * @param visitedNodes The set of towns visited in the current path.
     */
    private static void findPathsForScoutA(int u, int currentLength, Set<Integer> visitedNodes) {
        visitedNodes.add(u);

        // If Scout A reached the outpost, find the best path for Scout B
        if (u == outpost) {
            // Define forbidden nodes for B (Arin's path, excluding the outpost)
            Set<Integer> forbiddenForB = new HashSet<>(visitedNodes);
            forbiddenForB.remove(outpost);

            // Scout B's start cannot be on Arin's path
            if (forbiddenForB.contains(scoutB)) {
                visitedNodes.remove(u); // Backtrack
                return;
            }

            int lengthB = findShortestPathForScoutB(scoutB, outpost, forbiddenForB);

            if (lengthB != -1) {
                minPathSum = Math.min(minPathSum, (long) currentLength + lengthB);
            }

            visitedNodes.remove(u); // Backtrack
            return;
        }

        // Continue DFS for Scout A's path
        for (int v : adj.get(u)) {
            if (!visitedNodes.contains(v)) {
                findPathsForScoutA(v, currentLength + 1, visitedNodes);
            }
        }

        visitedNodes.remove(u); // Backtrack
    }

    /**
     * Uses BFS to find the shortest path for Scout B, avoiding forbidden towns.
     * @param start The starting town for Scout B.
     * @param end The outpost town.
     * @param forbidden The set of towns on Scout A's path.
     * @return The length of the shortest path for B, or -1 if no path exists.
     */
    private static int findShortestPathForScoutB(int start, int end, Set<Integer> forbidden) {
        Queue<int[]> queue = new ArrayDeque<>();
        queue.add(new int[]{start, 1}); // {town, length}

        Set<Integer> visitedByB = new HashSet<>(forbidden);
        visitedByB.add(start);

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int u = current[0];
            int len = current[1];

            if (u == end) {
                return len; // Found the shortest path
            }

            for (int v : adj.get(u)) {
                if (!visitedByB.contains(v)) {
                    visitedByB.add(v);
                    queue.add(new int[]{v, len + 1});
                }
            }
        }

        return -1; // No path found
    }
}