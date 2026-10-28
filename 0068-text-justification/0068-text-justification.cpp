class Solution {
public:
    int maxWidth;

    string createLine(int start, int end, int spacesBetweenWords,
                      int extraSpaces, vector<string>& words) {
        string line;

        for (int i = start; i < end; i++) {
            line += words[i];

            if (i == end - 1) {
                continue;
            }

            for (int j = 0; j < spacesBetweenWords; j++) {
                line += " ";
            }

            if (extraSpaces > 0) {
                line += " ";
                extraSpaces--;
            }
        }

        while (line.length() < maxWidth) {
            line += " ";
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        this->maxWidth = maxWidth;

        int start = 0;

        while (start < n) {
            int lettersCount = words[start].length();
            int end = start + 1;
            int spacesBetweenWords = 0;

            while (end < n &&
                   lettersCount + words[end].length() + spacesBetweenWords + 1 <= maxWidth) {
                lettersCount += words[end].length();
                spacesBetweenWords++;
                end++;
            }

            int totalSpaces = maxWidth - lettersCount;
            int baseSpaces = spacesBetweenWords == 0
                                 ? 0
                                 : totalSpaces / spacesBetweenWords;
            int extraSpaces = spacesBetweenWords == 0
                                  ? 0
                                  : totalSpaces % spacesBetweenWords;

            // The last line must be left-justified.
            if (end == n) {
                baseSpaces = 1;
                extraSpaces = 0;
            }

            result.push_back(
                createLine(start, end, baseSpaces, extraSpaces, words)
            );

            start = end;
        }

        return result;
    }
};