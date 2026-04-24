class Solutions {
    maxMeeting(start, end) {
        let meetings = [];
        for (let i = 0; i < start.length; i++) {
            meetings.push([end[i], start[i], i + 1]);
        }

        meetings.sort((a, b) => a[0] - b[0]);

        let ans = [];
        let lastEnd = -1;
        for (let i = 0; i < meetings.length; i++) {
            if (meetings[i][1] > lastEnd) {
                ans.push(meetings[i][2]);
                lastEnd = meetings[i][0];
            }
        }
        return ans;
    }
}
