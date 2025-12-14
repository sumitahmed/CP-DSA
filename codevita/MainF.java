import java.io.IOException;
import java.util.*;

public class MainF{

    static class Box {
        int x, y, width, height, area;
        String assignedString;

        public Box(int x, int y, int width, int height) {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.area = width * height;
        }
    }
    
    // Grid for the flood fill algorithm
    static int[][] componentGrid;
    static boolean[][] visited;
    static List<Integer> xCoords;
    static List<Integer> yCoords;
    static Set<String> verticalPartitions = new HashSet<>();
    static Set<String> horizontalPartitions = new HashSet<>();

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // Grid Height
        int M = sc.nextInt(); // Grid Width
        int L = sc.nextInt(); // Number of lines

        // Use TreeSets to get sorted, unique coordinates
        TreeSet<Integer> xSet = new TreeSet<>();
        TreeSet<Integer> ySet = new TreeSet<>();
        xSet.add(0);
        xSet.add(M);
        ySet.add(0);
        ySet.add(N);

        for (int i = 0; i < L; i++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            xSet.add(x1);
            ySet.add(y1);
            xSet.add(x2);
            ySet.add(y2);
            if (x1 == x2) { // Vertical line
                verticalPartitions.add(x1 + ":" + Math.min(y1, y2) + ":" + Math.max(y1, y2));
            } else { // Horizontal line
                horizontalPartitions.add(y1 + ":" + Math.min(x1, x2) + ":" + Math.max(x1, x2));
            }
        }

        int R = sc.nextInt();
        sc.nextLine(); 
        String[] strings = sc.nextLine().split(" ");
        sc.close();

        xCoords = new ArrayList<>(xSet);
        yCoords = new ArrayList<>(ySet);

        int gridHeight = yCoords.size() - 1;
        int gridWidth = xCoords.size() - 1;
        
        componentGrid = new int[gridHeight][gridWidth];
        visited = new boolean[gridHeight][gridWidth];
        
        int currentComponentId = 1;
        for (int i = 0; i < gridHeight; i++) {
            for (int j = 0; j < gridWidth; j++) {
                if (!visited[i][j]) {
                    floodFill(i, j, currentComponentId);
                    currentComponentId++;
                }
            }
        }
        
        int numBoxes = currentComponentId - 1;
        Map<Integer, List<int[]>> componentMap = new HashMap<>();
        for (int i = 0; i < gridHeight; i++) {
            for (int j = 0; j < gridWidth; j++) {
                int id = componentGrid[i][j];
                componentMap.computeIfAbsent(id, k -> new ArrayList<>()).add(new int[]{i, j});
            }
        }

        List<Box> boxes = new ArrayList<>();
        for (int i = 1; i <= numBoxes; i++) {
            List<int[]> cells = componentMap.get(i);
            int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
            int maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
            for (int[] cell : cells) {
                minY = Math.min(minY, cell[0]);
                minX = Math.min(minX, cell[1]);
                maxY = Math.max(maxY, cell[0]);
                maxX = Math.max(maxX, cell[1]);
            }
            int boxX = xCoords.get(minX);
            int boxY = yCoords.get(minY);
            int boxW = xCoords.get(maxX + 1) - boxX;
            int boxH = yCoords.get(maxY + 1) - boxY;
            boxes.add(new Box(boxX, boxY, boxW, boxH));
        }

        boxes.sort(Comparator.comparingInt((Box b) -> b.y).thenComparingInt(b -> b.x));
        for (int i = 0; i < boxes.size(); i++) {
            boxes.get(i).assignedString = strings[i];
        }

        boxes.sort((b1, b2) -> {
            if (b1.area != b2.area) return Integer.compare(b2.area, b1.area);
            if (b1.x != b2.x) return Integer.compare(b1.x, b2.x);
            return Integer.compare(b1.y, b2.y);
        });
        
        String raghusString = boxes.get(R - 1).assignedString;
        int totalValue = 0;
        for (char ch : raghusString.toCharArray()) {
            totalValue += ch;
        }

        System.out.println(totalValue);
    }
    
    private static void floodFill(int r, int c, int id) {
        if (r < 0 || r >= visited.length || c < 0 || c >= visited[0].length || visited[r][c]) {
            return;
        }
        
        visited[r][c] = true;
        componentGrid[r][c] = id;
        
        // Check right
        if (!hasVerticalPartition(c + 1, r)) {
            floodFill(r, c + 1, id);
        }
        // Check left
        if (!hasVerticalPartition(c, r)) {
            floodFill(r, c - 1, id);
        }
        // Check up
        if (!hasHorizontalPartition(r + 1, c)) {
            floodFill(r + 1, c, id);
        }
        // Check down
        if (!hasHorizontalPartition(r, c)) {
            floodFill(r - 1, c, id);
        }
    }

    private static boolean hasVerticalPartition(int xIndex, int yIndex) {
        int x = xCoords.get(xIndex);
        int y1 = yCoords.get(yIndex);
        int y2 = yCoords.get(yIndex + 1);
        return verticalPartitions.contains(x + ":" + y1 + ":" + y2);
    }
    
    private static boolean hasHorizontalPartition(int yIndex, int xIndex) {
        int y = yCoords.get(yIndex);
        int x1 = xCoords.get(xIndex);
        int x2 = xCoords.get(xIndex + 1);
        return horizontalPartitions.contains(y + ":" + x1 + ":" + x2);
    }
}