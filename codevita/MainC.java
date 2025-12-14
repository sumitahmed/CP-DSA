import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class MainC{

    static int M, N; // M: height, N: width
    static List<Rectangle> canvasRects = new ArrayList<>();
    static List<String> invalidCommands = new ArrayList<>();

    // Helper class to represent a rectangle
    static class Rectangle {
        int x, y, w, h;

        public Rectangle(int x, int y, int w, int h) {
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
        }

        /**
         * Corrected Method: Checks if this rectangle touches or overlaps with another.
         * Rectangles are considered colliding if they are not strictly separate.
         */
        public boolean intersectsOrTouches(Rectangle other) {
            // Check if the rectangles are strictly separate.
            boolean isSeparate =
                (this.x + this.w < other.x) || // this is strictly to the left of other
                (other.x + other.w < this.x) || // this is strictly to the right of other
                (this.y + this.h < other.y) || // this is strictly above other
                (other.y + other.h < this.y);  // this is strictly below other
            
            // If they are not separate, they must touch or overlap.
            return !isSeparate;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Rectangle rectangle = (Rectangle) o;
            return x == rectangle.x && y == rectangle.y && w == rectangle.w && h == rectangle.h;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y, w, h);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        int C = sc.nextInt();
        sc.nextLine(); // Consume newline

        for (int i = 0; i < C; i++) {
            String line = sc.nextLine();
            String[] parts = line.split(" ");
            String command = parts[0];

            switch (command) {
                case "draw":
                    handleDraw(line, parts);
                    break;
                case "remove":
                    handleRemove(parts);
                    break;
                case "shrink":
                case "extend":
                    handleModify(line, parts);
                    break;
            }
        }

        // Output invalid commands
        for (String invalid : invalidCommands) {
            System.out.println(invalid);
        }
        // Output final count of valid rectangles
        System.out.println(canvasRects.size());
        sc.close();
    }

    private static void handleDraw(String line, String[] parts) {
        int x = Integer.parseInt(parts[1]);
        int y = Integer.parseInt(parts[2]);
        int w = Integer.parseInt(parts[3]);
        int h = Integer.parseInt(parts[4]);
        
        Rectangle newRect = new Rectangle(x, y, w, h);
        boolean isValid = true;

        // 1. Check bounds
        if (x < 0 || y < 0 || x + w > N || y + h > M) {
            isValid = false;
        }

        // 2. Check for collisions with existing rectangles
        if (isValid) {
            for (Rectangle existingRect : canvasRects) {
                if (newRect.intersectsOrTouches(existingRect)) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            canvasRects.add(newRect);
        } else {
            invalidCommands.add(line);
        }
    }

    private static void handleRemove(String[] parts) {
        int x = Integer.parseInt(parts[1]);
        int y = Integer.parseInt(parts[2]);
        int w = Integer.parseInt(parts[3]);
        int h = Integer.parseInt(parts[4]);
        Rectangle toRemove = new Rectangle(x, y, w, h);
        canvasRects.remove(toRemove);
    }

    private static void handleModify(String line, String[] parts) {
        String commandType = parts[0];
        int idX = Integer.parseInt(parts[1]);
        int idY = Integer.parseInt(parts[2]);
        int newW = Integer.parseInt(parts[3]);
        int newH = Integer.parseInt(parts[4]);

        Rectangle target = null;
        for (Rectangle r : canvasRects) {
            if (r.x == idX && r.y == idY) {
                target = r;
                break;
            }
        }

        if (target == null) {
            invalidCommands.add(line); // Target rectangle not found
            return;
        }

        boolean isValid = true;
        
        // 1. Check shrink/extend logic
        if (commandType.equals("shrink")) {
            if (newW > target.w || newH > target.h) isValid = false;
        } else { // extend
            if (newW < target.w || newH < target.h) isValid = false;
        }
        
        // Create a temporary rectangle with the new dimensions to check for validity
        Rectangle potentialRect = new Rectangle(target.x, target.y, newW, newH);

        // 2. Check bounds
        if (isValid) {
            if (potentialRect.x + potentialRect.w > N || potentialRect.y + potentialRect.h > M) {
                isValid = false;
            }
        }

        // 3. Check for new collisions
        if (isValid) {
            for (Rectangle other : canvasRects) {
                if (other != target && potentialRect.intersectsOrTouches(other)) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            target.w = newW;
            target.h = newH;
        } else {
            invalidCommands.add(line);
        }
    }
}