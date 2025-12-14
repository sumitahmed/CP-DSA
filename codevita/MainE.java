import java.util.*;

public class MainE{

    static class Polynomial {
        long c_xx, c_xy, c_yy, c_x, c_y, c_const;

        Polynomial(long constant) { this.c_const = constant; }
        Polynomial(String var) {
            if (var.equals("x")) this.c_x = 1;
            else if (var.equals("y")) this.c_y = 1;
        }
        Polynomial(long c_xx, long c_xy, long c_yy, long c_x, long c_y, long c_const) {
            this.c_xx = c_xx; this.c_xy = c_xy; this.c_yy = c_yy;
            this.c_x = c_x; this.c_y = c_y; this.c_const = c_const;
        }

        static Polynomial add(Polynomial p1, Polynomial p2) {
            return new Polynomial(p1.c_xx + p2.c_xx, p1.c_xy + p2.c_xy, p1.c_yy + p2.c_yy,
                                  p1.c_x + p2.c_x, p1.c_y + p2.c_y, p1.c_const + p2.c_const);
        }

        static Polynomial multiply(Polynomial p1, Polynomial p2) {
            long n_xx = p1.c_const * p2.c_xx + p1.c_x * p2.c_x + p1.c_xx * p2.c_const;
            long n_xy = p1.c_const * p2.c_xy + p1.c_x * p2.c_y + p1.c_y * p2.c_x + p1.c_xy * p2.c_const;
            long n_yy = p1.c_const * p2.c_yy + p1.c_y * p2.c_y + p1.c_yy * p2.c_const;
            long n_x = p1.c_const * p2.c_x + p1.c_x * p2.c_const;
            long n_y = p1.c_const * p2.c_y + p1.c_y * p2.c_const;
            long n_const = p1.c_const * p2.c_const;
            return new Polynomial(n_xx, n_xy, n_yy, n_x, n_y, n_const);
        }

        int countOps() {
            int ops = 0;
            int termCount = 0;
            if (c_xx != 0) { termCount++; ops++; if (Math.abs(c_xx) != 1) ops++; }
            if (c_xy != 0) { termCount++; ops++; if (Math.abs(c_xy) != 1) ops++; }
            if (c_yy != 0) { termCount++; ops++; if (Math.abs(c_yy) != 1) ops++; }
            if (c_x != 0) { termCount++; if (Math.abs(c_x) != 1) ops++; }
            if (c_y != 0) { termCount++; if (Math.abs(c_y) != 1) ops++; }
            if (c_const != 0) { termCount++; }
            if (termCount > 1) ops += termCount - 1;
            
            // If only a constant term exists, ops should be 0.
            if (c_xx==0 && c_xy==0 && c_yy==0 && c_x==0 && c_y==0) return 0;
            
            return ops;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expression = sc.nextLine().replaceAll("\\s+", "");
        
        Polynomial simplified = parse(expression);
        int minOps = simplified.countOps();

        minOps = Math.min(minOps, checkForm1(simplified));
        minOps = Math.min(minOps, checkForm2(simplified));
        minOps = Math.min(minOps, checkForm3(simplified));

        System.out.println(minOps);
        sc.close();
    }

    private static int checkForm1(Polynomial p) { // (a1x+b1)(a2x+b2)
        long A = p.c_xx, D = p.c_x, F = p.c_const;
        if (A == 0 || F == 0) return Integer.MAX_VALUE;
        for (long[] a : getFactors(A)) {
            for (long[] b : getFactors(F)) {
                if (a[0] * b[1] + a[1] * b[0] == D) {
                    Polynomial p1 = new Polynomial(0, 0, 0, a[0], 0, b[0]);
                    Polynomial p2 = new Polynomial(0, 0, 0, a[1], 0, b[1]);
                    Polynomial remainder = new Polynomial(0, p.c_xy, p.c_yy, 0, p.c_y, 0);
                    return p1.countOps() + p2.countOps() + 1 + remainder.countOps() + (remainder.countOps() > 0 ? 1 : 0);
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    private static int checkForm2(Polynomial p) { // (a1x+b1)(a2y+b2)
        long B = p.c_xy, D = p.c_x, E = p.c_y, F = p.c_const;
        if (B == 0 || F == 0) return Integer.MAX_VALUE;
        for (long[] a : getFactors(B)) {
            for (long[] b : getFactors(F)) {
                if (a[0] * b[1] == D && a[1] * b[0] == E) {
                    Polynomial p1 = new Polynomial(0, 0, 0, a[0], 0, b[0]);
                    Polynomial p2 = new Polynomial(0, 0, 0, 0, a[1], b[1]);
                    Polynomial remainder = new Polynomial(p.c_xx, 0, p.c_yy, 0, 0, 0);
                    return p1.countOps() + p2.countOps() + 1 + remainder.countOps() + (remainder.countOps() > 0 ? 1 : 0);
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    private static int checkForm3(Polynomial p) { // (a1x+b1y)(a2x+b2)
        long A = p.c_xx, B = p.c_xy, D = p.c_x, E = p.c_y;
        if (A == 0 || B == 0 || D == 0 || E == 0) return Integer.MAX_VALUE;
        if (A * E != B * D) return Integer.MAX_VALUE;
        for (long[] b_factors : getFactors(E)) {
            long b1 = b_factors[0], b2 = b_factors[1];
            if (b1 == 0) continue;
            if (B % b1 != 0 || D % b2 != 0) continue;
            long a2 = B / b1;
            long a1 = D / b2;
            if (a1 * a2 == A) {
                Polynomial p1 = new Polynomial(0, 0, 0, a1, b1, 0);
                Polynomial p2 = new Polynomial(0, 0, 0, a2, 0, b2);
                Polynomial remainder = new Polynomial(0, 0, p.c_yy, 0, 0, p.c_const);
                return p1.countOps() + p2.countOps() + 1 + remainder.countOps() + (remainder.countOps() > 0 ? 1 : 0);
            }
        }
        return Integer.MAX_VALUE;
    }

    private static List<long[]> getFactors(long n) {
        List<long[]> factors = new ArrayList<>();
        if (n == 0) return factors;
        for (long i = 1; i * i <= Math.abs(n); i++) {
            if (n % i == 0) {
                long j = n / i;
                factors.add(new long[]{i, j}); factors.add(new long[]{j, i});
                factors.add(new long[]{-i, -j}); factors.add(new long[]{-j, -i});
            }
        }
        return factors;
    }

    private static Polynomial parse(String s) {
        Deque<Polynomial> values = new ArrayDeque<>();
        Deque<Character> ops = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                long num = 0;
                while (i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                i--;
                values.push(new Polynomial(num));
            } else if (c == 'x' || c == 'y') {
                values.push(new Polynomial(String.valueOf(c)));
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (ops.peek() != '(') applyOp(ops.pop(), values);
                ops.pop();
            } else if (c == '+' || c == '*') {
                while (!ops.isEmpty() && hasPrecedence(c, ops.peek())) applyOp(ops.pop(), values);
                ops.push(c);
            }
        }
        while (!ops.isEmpty()) applyOp(ops.pop(), values);
        return values.pop();
    }

    private static boolean hasPrecedence(char op1, char op2) {
        if (op2 == '(' || op2 == ')') return false;
        return op1 != '*';
    }

    private static void applyOp(char op, Deque<Polynomial> values) {
        Polynomial b = values.pop();
        Polynomial a = values.pop();
        if (op == '+') values.push(Polynomial.add(a, b));
        else if (op == '*') values.push(Polynomial.multiply(a, b));
    }
}