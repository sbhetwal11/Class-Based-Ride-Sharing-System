Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance |

    Ride class >> newID: id pickup: pickup dropoff: dropoff distance: dist [
        ^ self new initID: id pickup: pickup dropoff: dropoff distance: dist
    ]

    initID: id pickup: pickup dropoff: dropoff distance: dist [
        rideID := id.
        pickupLocation := pickup.
        dropoffLocation := dropoff.
        distance := dist.
        ^ self
    ]

    rideDetails [
        ^ 'Ride#', rideID, ' from ', pickupLocation, ' to ', dropoffLocation,
           ' (', distance printString, ' mi)'
    ]

    fare [ self subclassResponsibility ]
]


Ride subclass: StandardRide [
    fare [
        ^ distance * 1.0  "base fare"
    ]
]


Ride subclass: PremiumRide [
    fare [
        ^ distance * 1.5  "premium fare"
    ]
]


Object subclass: Driver [
    | name rating assignedRides |

    Driver class >> newName: n rating: r [
        ^ self new initName: n rating: r
    ]

    initName: n rating: r [
        name := n.
        rating := r.
        assignedRides := OrderedCollection new.
        ^ self
    ]

    assignRide: ride [
        assignedRides add: ride.
    ]

    showDetails [
        "Use printString to safely convert numbers to text"
        Transcript show: 'Driver: ', name, ' (Rating ', rating printString, ')'; cr.
        Transcript show: 'Assigned Rides (' , assignedRides size printString , '):'; cr.
        assignedRides do: [:ride |
            Transcript show: '  - ', ride rideDetails, ' Fare $', (ride fare) printString; cr.
        ].
    ]
]


Object subclass: Rider [
    | name rideHistory |

    Rider class >> newName: n [
        ^ self new initName: n
    ]

    initName: n [
        name := n.
        rideHistory := OrderedCollection new.
        ^ self
    ]

    takeRide: ride [
        rideHistory add: ride.
    ]

    showDetails [
        Transcript show: 'Rider: ', name; cr.
        Transcript show: 'Ride History (', rideHistory size printString, '):'; cr.
        rideHistory do: [:ride |
            Transcript show: '  - ', ride rideDetails, ' Fare $', (ride fare) printString; cr.
        ].
    ]
]


" --- MAIN EXECUTION --- "

| r1 r2 d1 rider1 |
r1 := StandardRide newID: '001' pickup: 'Downtown' dropoff: 'Airport' distance: 12.0.
r2 := PremiumRide newID: '002' pickup: 'Stadium' dropoff: 'Hotel' distance: 5.5.

d1 := Driver newName: 'Alex Johnson' rating: 4.9.

rider1 := Rider newName: 'Alan Walker'.

d1 assignRide: r1.
d1 assignRide: r2.

rider1 takeRide: r1.
rider1 takeRide: r2.

Transcript show: 'All Rides:'; cr.
Transcript show: r1 rideDetails, ' Fare $', (r1 fare) printString; cr.
Transcript show: r2 rideDetails, ' Fare $', (r2 fare) printString; cr; cr.

d1 showDetails. Transcript cr.
rider1 showDetails.
