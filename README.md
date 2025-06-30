# CS-300

## Course Planner Program

This project lets users load a CSV of course data, view all courses in alphanumeric order, and look up individual courses with their prerequisites.

---

### Key Features

- CSV parser loads course number, title, and prereqs into a map
- Menu lets user load data, print all courses, or search by course ID
- Sorted output by course number (A-Z)
- Shows prereqs if present—or says “None” if not
- Case-insensitive search with friendly output

---

### Runtime & Memory Analysis (Project One)

Compared three data structures:  
- Vector: Compact, easy to code, but slow on search/sort  
- Hash Table: Fast lookup (O(1)), but unordered output  
- Binary Search Tree: Balanced performance + sorted data by default  

Recommendation: Use a BST. It gives you fast lookups and naturally sorted output with minimal extra code or overhead.

---

### Reflection

**Q1: What problem were you solving?**  
I needed to load and search through course data efficiently, letting users view info or get a clean course list.

**Q2: How did you approach it?**  
Focused on structure first—parsing cleanly and organizing the data into searchable maps. Then made the UI simple.

**Q3: Roadblocks?**  
Some CSVs were inconsistent, and I had to build around those quirks. Also had to rework output formatting a bit for readability.

**Q4: How did this expand your skills?**  
Helped me understand the real cost of search/sort strategies and how much design choices matter when scaling a program.

**Q5: How did it change how you write code?**  
I’m more intentional now about keeping code readable, splitting logic into clean functions, and picking the right tool for the job.
