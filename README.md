# GPA-Calculator

A lightweight GPA calculator that supports **retake handling**, **political course flags**, and both **command-line** and **Qt GUI** versions.

📘 **中文说明：请参考 README_CN.md**  
👉 https://github.com/NPgreatest/GPA-Calculator/README_CN.md  
(更新时请替换为你的实际仓库链接)

---

## 1. Command-Line Version

### 📍 Transcript File Location
Place the transcript at:

```

D:\transcript.txt

```

### 📍 File Format

```

<course_name> <credit> <score> <is_political> <is_retake>

```

Example:

```

大学英语Ⅱ 2.0 67 0 0
钢琴音乐赏析 1.5 80 0 0
高等数学（下） 6.0 70 0 1
高等数学（下） 6.0 98 0 0
数据库原理 3.0 92 0 0

```

**Retake Rule**
- Retake entries **must appear before** the final/latest course.
- Course name must match exactly.
- The calculator will automatically select the correct grade.

---

## 2. Qt GUI Version

The Qt version provides:

- Batch import of transcript lines  
- Automatic retake recognition based on course names  
- GPA calculation by ECUST rules or custom rules  
- Highlighting, tagging, and easy editing  
- Clean and intuitive student-grade UI  

### 📍 Qt Transcript Format

Simplified input:

```

<course_name> <credit> <score>

```

Example:

```

大学英语Ⅱ 2.0 67
钢琴音乐赏析 1.5 80
高等数学（下） 6.0 70   ← Retake (older)
高等数学（下） 6.0 98   ← Final score

```

The GUI will automatically detect retake relationships.

---

## 3. Example Transcript

(Replace this section with your actual example)

```

保险理财规划 2.0 68
创业基础 1.0 84
……
中国文化导论 1.0 64

```

---

## 4. Example Screenshot

Insert your Qt screenshot here:

![Example UI](/pic/example_en.png)

---

## License

MIT License
