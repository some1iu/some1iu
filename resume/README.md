# Resume — HolboxAI (AI Research Engineer / Scientist)

- `main.tex` — the Overleaf-ready resume (pdfLaTeX, single page A4).
- `kangana_khurana_resume_preview.pdf` — a **layout preview only** (typeset outside LaTeX to check
  length/spacing). Compile `main.tex` on Overleaf for the real PDF.

## Import into Overleaf

1. Overleaf → **New Project → Blank Project**.
2. Delete the default `main.tex`, paste in the contents of this `main.tex`.
3. **Menu → Compiler: pdfLaTeX → Recompile**. No extra packages or files needed.

## Fill in before sending (everything in `[square brackets]`)

- `[City], India` in the header, plus `[+91 XX XXX XXXXX]`.
- LinkedIn URL — replace `linkedin.com/in/PLACEHOLDER` (or delete that segment).
- `[University Name]`, `[Start Year] – [End Year]`, current year, optional CGPA.
- Any extra coursework in the bracketed `[add others, …]` slot.
- Delete the "HONESTY NOTE" comment block at the top of `main.tex`.

## What is claimed, and why

| Claim | Source |
| --- | --- |
| Python/MySQL console app, query builder, recommendations, bill file, error handling | verified in `some1iu/movie-streaming-platform` (`movie_streaming.py`, ~820 lines) |
| Class XII CBSE, Delhi Public School, Pune, 2024–25 | stated in that repo's README |
| Full-stack contribution to Next.js/Express/Prisma/PostgreSQL event platform | repo `chetisha28/incursion-acm`, plus your own account of your contribution |
| Typebot monorepo exploration, no upstream contribution | your fork `some1iu/typebot.io`, plus your account |

## What is deliberately **not** claimed

No PyTorch training, Transformer/VLM implementation, RLHF/DPO/GRPO implementation, paper
reproduction, NumPy/Pandas proficiency, or research output — your repositories contain no evidence for
these. Deep learning, RL and post-training appear only under "Research Interests" with an explicit
"study interests; not yet hands-on" note, and NumPy/Pandas are listed under "Currently learning".

When you have code to back it up (even a small from-scratch implementation with a repo link), add it as
a project entry — the fastest honest way to strengthen this CV for this role is:

1. a from-scratch autograd + small MLP in NumPy, with gradient-check tests;
2. a character-level Transformer trained from scratch, with loss curves and a short write-up;
3. a toy DPO/GRPO or REINFORCE implementation on a small task, with results you can explain.
